package com.example.mpdemo.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.example.mpdemo.entity.Inventory;
import org.apache.ibatis.annotations.*;

import java.util.List;

@Mapper
public interface InventoryMapper extends BaseMapper<Inventory> {

    @Select("select * from inventory where id=#{i_id}")
    Inventory selectByIid(int i_id);

    @Select("select * from inventory")
    @Results(
            {
                    @Result(column = "id",property = "id"),
                    @Result(column = "name",property = "name"),
                    @Result(column = "num",property = "num"),
                    @Result(column = "recent",property = "recent"),
                    @Result(column = "id",property = "items",javaType = List.class,
                            //调用ItemsMapper中的selectById
                            //！此处应为多对一关系，不应使用 @Many
                        many = @Many(select = "com.example.mpdemo.mapper.ItemsMapper.selectByIid")
                    )
            }
    )
    List<Inventory> selectAllInventoryAndItems();
}
