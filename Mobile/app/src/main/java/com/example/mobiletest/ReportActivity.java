package com.example.mobiletest;

import android.os.Bundle;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.example.mobiletest.models.Automobile;
import com.example.mobiletest.storage.DbHelper;

import java.util.List;

public class ReportActivity extends AppCompatActivity {

    DbHelper db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_report);
        db = new DbHelper(this);
        TextView reportLabel = findViewById(R.id.reportLabel);
        reportLabel.setText(db.report());
    }
}