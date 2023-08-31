package com.example.mpdemo.entity;

public class Bill {
    private int id;
    private String used;
    private int expends;
    private int funds;

    public int getId() {
        return id;
    }

    public int getExpends() {
        return expends;
    }

    public void setExpends(int expends) {
        this.expends = expends;
    }

    public int getFunds() {
        return funds;
    }

    public void setFunds(int funds) {
        this.funds = funds;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getUsed() {
        return used;
    }

    public void setUsed(String used) {
        this.used = used;
    }

}
