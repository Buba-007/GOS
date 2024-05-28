package com.example.mobiletest.storage;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import com.example.mobiletest.models.Automobile;
import com.example.mobiletest.models.STATUS;

import java.util.ArrayList;
import java.util.List;

public class DbHelper extends SQLiteOpenHelper {
    private static final String DATABASE_NAME = "automobiles_db";
    private static final int DATABASE_VERSION = 1;
    private static final String TABLE_NAME = "automobiles";

    public DbHelper(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String createTableQuery = "CREATE TABLE IF NOT EXISTS " + TABLE_NAME +
                " (id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                "name TEXT, " +
                "status TEXT, " +
                "flm TEXT)";
        db.execSQL(createTableQuery);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        // Здесь можно обновить структуру таблицы при изменении версии базы данных
    }

    public List<Automobile> readAll() {
        List<Automobile> automobilesList = new ArrayList<>();
        String selectQuery = "SELECT * FROM " + TABLE_NAME;
        SQLiteDatabase db = this.getWritableDatabase();
        Cursor cursor = db.rawQuery(selectQuery, null);

        if (cursor.moveToFirst()) {
            do {
                Automobile automobile = new Automobile();
                int idIndex = cursor.getColumnIndex("id");
                if (idIndex != -1) automobile.id = cursor.getInt(idIndex);
                int nameIndex = cursor.getColumnIndex("name");
                if (nameIndex != -1) automobile.Name = cursor.getString(nameIndex);
                int statusIndex = cursor.getColumnIndex("status");
                if (statusIndex != -1) automobile.status = STATUS.valueOf(cursor.getString(statusIndex));
                int flmIndex = cursor.getColumnIndex("flm");
                if (flmIndex != -1) automobile.FLM = cursor.getString(flmIndex);
                automobilesList.add(automobile);
            } while (cursor.moveToNext());
        }

        cursor.close();
        db.close();
        return automobilesList;
    }

    public void insert(Automobile automobile) {
        SQLiteDatabase db = this.getWritableDatabase();

        ContentValues values = new ContentValues();
        values.put("name", automobile.Name);
        values.put("status", automobile.status.toString());
        values.put("flm", automobile.FLM);

        db.insert(TABLE_NAME, null, values);
        db.close();
    }

    public int updateAutomobile(Automobile automobile) {
        SQLiteDatabase db = this.getWritableDatabase();

        ContentValues values = new ContentValues();
        values.put("name", automobile.Name);
        values.put("status", automobile.status.toString());
        values.put("flm", automobile.FLM);

        return db.update(TABLE_NAME, values, "id = ?", new String[]{String.valueOf(automobile.id)});
    }

    public void clearDВ() {
        SQLiteDatabase db = this.getWritableDatabase();
        db.delete(TABLE_NAME, null, null);
        db.close();
    }

    public String report() {
        List<Automobile> automobilesList = new ArrayList<>();
        String countQuery = "SELECT status, COUNT(*) AS count FROM " + TABLE_NAME + " GROUP BY status";
        SQLiteDatabase db = this.getWritableDatabase();
        Cursor cursor = db.rawQuery(countQuery, null);
        String result = "";

        if (cursor.moveToFirst()) {
            do {
                result += "Записей со статусом ";
                int statusIndex = cursor.getColumnIndex("status");
                if (statusIndex != -1) result += cursor.getString(statusIndex);
                result += " - ";
                int countIndex = cursor.getColumnIndex("count");
                if (countIndex != -1) result += cursor.getString(countIndex);
                result += "\n";
            } while (cursor.moveToNext());
        }
        cursor.close();
        return result;
    }
}