package com.example.springtest02.controller;

import ch.qos.logback.core.net.SyslogOutputStream;
import com.example.springtest02.entity.User;
import org.springframework.web.bind.annotation.*;

@RestController
public class HelloController {

    @RequestMapping(value = "hello", method = RequestMethod.GET)
    public String hello(String nickname, String phone) {
        return "你好" + nickname + " " + phone;
    }

    @RequestMapping(value = "/postTest1", method = RequestMethod.POST)
    public String postTest1() {
        return "POST请求";
    }

    @RequestMapping(value = "postTest2", method = RequestMethod.POST)
    public String postTest2(String username, String password) {
        System.out.println("username:" + username);
        System.out.println("password:" + password);
        return "POST请求";
    }

    @RequestMapping(value = "postTest3", method = RequestMethod.POST)
    public String postTest3(User user) {
        System.out.println(user);
        return "POST请求";
    }

    @RequestMapping(value = "postTest4", method = RequestMethod.POST)
    public String postTest4(@RequestBody User user) {
        System.out.println(user);
        return "Post请求";
    }

    @RequestMapping(value = "/test/**")
    public String valueTest() {
        return "test";
    }
}
