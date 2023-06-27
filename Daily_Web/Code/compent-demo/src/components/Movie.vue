<template>
    <div>
        <h1>{{ title }}</h1>
        <span>{{ rating }}</span>
        <button @click="fun">点击收藏</button>
    </div>
</template>

<script>
export default {
    name: 'Movie',
    props:["title","rating"],
    data: function () {
        return {
            
        }
    },
    methods:{
        fun:function(){
            alert("收藏成功");
        }
    }
}
</script>

<style scoped>
h1{
    color:red;
}
</style>