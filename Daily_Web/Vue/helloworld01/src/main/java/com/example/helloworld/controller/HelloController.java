package com.example.helloworld.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {

    //  http://www.baidu.com/s/xx
    //  http://localhost:8080/hello
    @GetMapping("/hello")
    public String hello() {
        return "hello world";
    }
}
