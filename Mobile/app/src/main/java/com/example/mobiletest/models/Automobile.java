package com.example.mobiletest.models;


import java.io.Serializable;

public class Automobile implements Serializable {
    public Integer id;
    public String Name;
    public STATUS status;
    public String FLM;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public STATUS getStatus() {
        return status;
    }

    public void setStatus(STATUS status) {
        this.status = status;
    }

    public String getFLM() {
        return FLM;
    }

    public void setFLM(String FLM) {
        this.FLM = FLM;
    }

    @Override
    public String toString() {
        if (this.getStatus() == STATUS.Выдан) {
            return  "Название: " + this.getName() + " Статус: " + this.getStatus().toString() + " - " + this.getFLM();
        }
        return  "Название: " + this.getName() + " Статус: " + this.getStatus().toString();
    }
}
