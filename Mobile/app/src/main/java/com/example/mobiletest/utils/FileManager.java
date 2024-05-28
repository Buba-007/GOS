package com.example.mobiletest.utils;

import android.content.Context;

import com.example.mobiletest.models.Automobile;
import com.google.gson.Gson;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import com.google.gson.reflect.TypeToken;
import java.lang.reflect.Type;
import java.util.List;

public class FileManager {

    public List<Automobile> read(Context context, String filename) {
        Gson gson = new Gson();
        String jsonString = "";

        StringBuilder stringBuilder = new StringBuilder();
        try {
            FileInputStream fis = context.openFileInput(filename);
            InputStreamReader isr = new InputStreamReader(fis);
            BufferedReader bufferedReader = new BufferedReader(isr);
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                stringBuilder.append(line).append("\n");
            }
            fis.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        jsonString = stringBuilder.toString();
        Type listType = new TypeToken<List<Automobile>>() {}.getType();
        return gson.fromJson(jsonString, listType);
    }

    public void write(Context context, List<Automobile> automobiles, String filename) {
        Gson gson = new Gson();
        String jsonString = gson.toJson(automobiles);

        try {
            context.getApplicationContext().openFileOutput(
                    filename, Context.MODE_PRIVATE
            ).write(jsonString.getBytes());

        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}