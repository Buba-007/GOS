package com.example.mobiletest.fragments;

import android.content.res.ColorStateList;
import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;

import com.example.mobiletest.R;
import com.example.mobiletest.models.Automobile;
import com.example.mobiletest.models.STATUS;
import com.example.mobiletest.storage.DbHelper;
import com.google.android.material.textfield.TextInputEditText;
import com.google.android.material.textfield.TextInputLayout;

import java.util.ArrayList;
import java.util.List;


public class AutoFragment extends Fragment {

    ListFragment listFragment;
    DbHelper db;
    Automobile auto = null;;

    public AutoFragment() {
        // Required empty public constructor
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        db = new DbHelper(getActivity());
        listFragment = new ListFragment();
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_auto, container, false);

        TextInputEditText name = view.findViewById(R.id.autoName);
        TextInputEditText flm = view.findViewById(R.id.autoFLM);
        TextInputLayout flm_lay = view.findViewById(R.id.autoFLMLay);
        Spinner spinner = view.findViewById(R.id.spinnerStatus);
        Button buttonSave = view.findViewById(R.id.buttonSave);
        Button buttonCancel = view.findViewById(R.id.buttonCancel);
        flm.setEnabled(false);
        flm.setBackgroundColor(getResources().getColor(R.color.grey));
        List<String> statusList = new ArrayList<>();
        // Пройдемся по значениям enum и добавим их в список строк
        for (STATUS status : STATUS.values()) {
            statusList.add(status.toString());
        }
        // Создание ArrayAdapter для связи данных с Spinner
        ArrayAdapter<String> adapter = new ArrayAdapter<>(getContext(), android.R.layout.simple_spinner_item, statusList);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        // Привязка ArrayAdapter к Spinner
        spinner.setAdapter(adapter);

        Bundle args = getArguments();
        if(args != null) {
            auto = (Automobile) getArguments().getSerializable("automobile");
        }
        if (auto != null) {
            name.setText(auto.Name);
            spinner.setSelection(adapter.getPosition(auto.status.toString()));
            flm.setText(auto.FLM);
        } else {
            spinner.setVisibility(view.INVISIBLE);
            flm_lay.setVisibility(view.INVISIBLE);
        }
        flm.setHint("");
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String selectedStatus = statusList.get(position);

                if (selectedStatus.equals(STATUS.Выдан.toString())) {
                    flm.setEnabled(true);
                    flm.setBackgroundColor(getResources().getColor(R.color.white));
                } else {
                    flm.setEnabled(false);
                    flm.setBackgroundColor(getResources().getColor(R.color.grey));
                    flm.setText("");
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

        buttonSave.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (auto != null) {
                    auto.setName(name.getText().toString());
                    auto.setStatus(STATUS.valueOf(spinner.getSelectedItem().toString()));
                    auto.setFLM(flm.getText().toString());
                    db.updateAutomobile(auto);
                    replaceFragment(listFragment);
                } else {
                    Automobile a = new Automobile();
                    a.setName(name.getText().toString());
                    a.setStatus(STATUS.Принят);
                    a.setFLM("");
                    db.insert(a);
                    replaceFragment(listFragment);
                }
            }
        });


        buttonCancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                replaceFragment(listFragment);
            }
        });

        return view;
    }

    private void replaceFragment(Fragment fragment) {
        FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
        fragmentTransaction.replace(R.id.fragmentContainer, fragment);
        fragmentTransaction.commit();
    }
}