package com.example.mobiletest.fragments;

import static androidx.core.app.ActivityCompat.recreate;

import android.content.Intent;
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
import android.widget.ListView;
import android.widget.Toast;

import com.example.mobiletest.R;
import com.example.mobiletest.ReportActivity;
import com.example.mobiletest.models.Automobile;
import com.example.mobiletest.storage.DbHelper;
import com.example.mobiletest.utils.FileManager;

import java.util.ArrayList;
import java.util.List;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link ListFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class ListFragment extends Fragment {
    private final String filename = "data.json";
    AutoFragment autoFragment;
    DbHelper db;
    FileManager fm;
    List<Automobile> automobiles;
    List<String> autoViewSet;

    public ListFragment() {
        // Required empty public constructor
    }

    public static ListFragment newInstance(String param1, String param2) {
        ListFragment fragment = new ListFragment();
        Bundle args = new Bundle();
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        db = new DbHelper(getActivity());
        fm = new FileManager();
        autoFragment = new AutoFragment();
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_list, container, false);

        Button buttonAdd = view.findViewById(R.id.buttonAdd);
        Button buttonExport = view.findViewById(R.id.buttonExport);
        Button buttonImport = view.findViewById(R.id.buttonImport);
        Button buttonReport = view.findViewById(R.id.buttonReport);
        ListView listView = view.findViewById(R.id.listAuto);
        automobiles = db.readAll();
        autoViewSet = new ArrayList<>();
        for(Automobile auto : automobiles) {
            autoViewSet.add(auto.toString());
        }

        ArrayAdapter<String> adapter = new ArrayAdapter<>(getActivity(), android.R.layout.simple_list_item_1, autoViewSet);
        listView.setAdapter(adapter);

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Bundle args = new Bundle();
                args.putSerializable("automobile", automobiles.get(position)); // Помещаем данные в Bundle
                autoFragment = new AutoFragment();
                autoFragment.setArguments(args);
                replaceFragment(autoFragment);
            }
        });

        buttonAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                replaceFragment(autoFragment);
            }
        });

        buttonReport.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getActivity(), ReportActivity.class);
                startActivity(intent);
            }
        });

        buttonImport.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                db.clearDВ();
                try {
                    List<Automobile> imported = fm.read(getActivity(), filename);
                    for (Automobile a : imported) {
                        db.insert(a);
                    }
                    Toast.makeText(getActivity().getApplicationContext(), "Успешно: Данные импортированы", Toast.LENGTH_SHORT).show();
                    recreate(getActivity());
                } catch (Exception e) {
                    Toast.makeText(getActivity().getApplicationContext(), "Ошибка: Данные не импортированы", Toast.LENGTH_SHORT).show();
                }
            }
        });

        buttonExport.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    fm.write(getActivity(), automobiles, filename);
                    Toast.makeText(getActivity().getApplicationContext(), "Успешно: Файл сохранён", Toast.LENGTH_SHORT).show();
                } catch (Exception e) {
                    Toast.makeText(getActivity().getApplicationContext(), "Ошибка: Файл не сохранён", Toast.LENGTH_SHORT).show();
                }
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