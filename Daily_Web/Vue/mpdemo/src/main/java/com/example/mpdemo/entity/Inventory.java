package com.example.mpdemo.entity;

import com.baomidou.mybatisplus.annotation.TableField;

import java.util.List;

public class Inventory {
    private int id;
    private String name;
    private int num;
    private String recent;

    @TableField(exist = false)
    private List<Items> items;

    @Override
    public String toString() {
        return "Inventory{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", num=" + num +
                ", recent='" + recent + '\'' +
                ", items=" + items +
                '}';
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
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

    public String getRecent() {
        return recent;
    }

    public void setRecent(String recent) {
        this.recent = recent;
    }

    public List<Items> getItems() {
        return items;
    }

    public void setItems(List<Items> items) {
        this.items = items;
    }
}
