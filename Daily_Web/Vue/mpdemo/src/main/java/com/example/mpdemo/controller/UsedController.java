package com.example.mpdemo.controller;

import com.example.mpdemo.entity.Used;
import com.example.mpdemo.mapper.UsedMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class UsedController {

    @Autowired
    private UsedMapper usedMapper;

    @GetMapping("/ess/used/get")
    public List<Used> query(){
        List<Used> list=usedMapper.selectList(null);
        list.forEach(System.out::println);
        return list;
    }

    @PostMapping("/ess/used/save")
    public String save(Used used) {
        int i = usedMapper.insert(used);
        if (i > 0){
            return "插入成功";
        }else{
            return "插入失败";
        }
    }
}
