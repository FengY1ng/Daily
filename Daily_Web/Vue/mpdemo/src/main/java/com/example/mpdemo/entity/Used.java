package com.example.mpdemo.entity;

public class Used {
    private int i_id;
    private String name;
    private int num;

    @Override
    public String toString() {
        return "Used{" +
                "i_id=" + i_id +
                ", name='" + name + '\'' +
                ", num=" + num +
                '}';
    }

    public int getI_id() {
        return i_id;
    }

    public void setI_id(int i_id) {
        this.i_id = i_id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }
}
