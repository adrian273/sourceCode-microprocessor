<template>
  <div id="app">
    <div class="main">
      <h1>Arduino - VUEJS - SOCKET.io</h1>
      <template v-for="(v, k) in form">
        <label for="" :key="k">
          <p-check
            class="p-icon p-fill p-tada"
            v-model="form[k].on"
            :true-value="1"
            :false-value="0"
            @change="ledON"
            color="warning"
            >{{ form[k].title }}
            <i slot="extra" class="icon mdi mdi-flash"></i>
          </p-check>
          <img src="./assets/on.png" alt="" v-if="form[k].on == 1" />
          <img src="./assets/off.png" alt="" v-if="form[k].on == 0" />
        </label>
      </template>
      <h3>@github adrian273</h3>
    </div>
  </div>
</template>

<script>
/***
 * Adrian Verdugo ( アドリアン　)
 * @github adrian273
 * @since 10/29/2020
 *
 */
import io from "socket.io-client";
var socket = io.connect("http://localhost:4000");

export default {
  data() {
    return {
      form: {
        led1: { valu: 13, on: "0", title: "LED A" },
        led2: { valu: 12, on: "0", title: "LED B" },
        led3: { valu: 7, on: "0", title: "LED C" },
        led4: { valu: 4, on: "0", title: "LED D" },
      },
    };
  },
  methods: {
    ledON(event) {
      socket.emit("ledOn", this.form);
    },
  },
};
</script>
<style>
#app {
  text-align: center;
}

.small {
  max-width: 600px;
  margin: 150px auto;
}

img {
  width: 10%;
}

.main {
  padding: 10px;
  margin: 10px;
  padding-top: 5%;
  display: inline-block;
}
</style>