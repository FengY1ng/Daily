package com.example.mpdemo.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.example.mpdemo.entity.Inventory;
import com.example.mpdemo.entity.Items;
import org.apache.ibatis.annotations.*;

import java.util.List;


@Mapper//根据Items类中的查询语句完成Inventory的多表查询
public interface ItemsMapper extends BaseMapper<Items> {
    @Select("select * from items where id = #{i_id}")
    List<Items> selectByIid(int i_id);

    @Select("select * from items")
    @Results({
            @Result(column = "id",property = "id"),
            @Result(column = "name",property = "name"),
            @Result(column = "price",property = "price"),
            @Result(column = "i_id",property = "inventory",javaType = Inventory.class,
                many=@Many(select="com.example.mpdemo.mapper.UserMapper.selectById")
            )
    })
    List<Items> selectAllInventoryAndItems();

}
