package com.example.mpdemo.controller;

import com.example.mpdemo.entity.Inventory;
import com.example.mpdemo.mapper.InventoryMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class InventoryController {

    @Autowired
    private InventoryMapper inventoryMapper;

    @GetMapping("/ess/inventory/get")
    public List<Inventory> query(){
        return inventoryMapper.selectAllInventoryAndItems();
//        List<Inventory> list=inventoryMapper.selectList(null);
//        list.forEach(System.out::println);
//        return list;
    }

    @PostMapping("/ess/inventory/save")
    public String save(Inventory inventory){
        int i=inventoryMapper.insert(inventory);
        if(i>0){
            return "插入成功";
        }else {
            return "插入失败";
        }
    }
}
