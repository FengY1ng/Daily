package com.example.mpdemo.controller;

import com.example.mpdemo.entity.Bill;
import com.example.mpdemo.mapper.BillMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class BillController {
    @Autowired
    private BillMapper billMapper;

    @GetMapping("/ess/bill/get")
    public List query(){
        List<Bill> list=billMapper.selectList(null);
        list.forEach(System.out::println);
        return list;
    }

    @PostMapping("/ess/bill/save")
    public String save(Bill bill){
        int i=billMapper.insert(bill);
        if(i>0){
            return "插入成功";
        }else {
            return "插入失败";
        }
    }
}
