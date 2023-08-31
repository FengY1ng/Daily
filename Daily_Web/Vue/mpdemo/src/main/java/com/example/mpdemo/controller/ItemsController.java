package com.example.mpdemo.controller;

import com.example.mpdemo.entity.Items;
import com.example.mpdemo.mapper.ItemsMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class ItemsController {

    @Autowired
    private ItemsMapper itemsMapper;

    @GetMapping("/ess/items/get")
    public List<Items> entity(){
        List<Items> list=itemsMapper.selectList(null);
        list.forEach(System.out::println);
        return list;
    }

    @GetMapping("/ess/items/findAll")
    public List<Items> findAll(){
        return itemsMapper.selectAllInventoryAndItems();
    }

    @PostMapping("/ess/items/save")
    public String save(Items item){
        int i=itemsMapper.insert(item);
        if(i>0){
            return "插入成功";
        }else {
            return "插入失败";
        }
    }
}
