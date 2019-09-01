<template>
  <div id="app" class="bg-light">
    <div>
      <div>
        Honorario
      </div>
      <input class="form-control" placeholder="0" type="text" />
    </div>
    <div>
      <div>
        Liquidación
      </div>
      <input class="form-control" placeholder="0" type="text" />
    </div>
    <div>
      <div>
        Mes
      </div>
      <select id="" name="">
        <option v-for="i in 12">
          {{i}}
        </option>
      </select>
    </div>
    <div class="btn btn-primary">
      Añadir
    </div>
  </div>
</template>
<script>
export default {
  name: 'HelloWorld',
  props: {
    msg: String
  },
  data: {
    todos: [
      { text: "Learn JavaScript", done: false },
      { text: "Learn Vue", done: false },
      { text: "Play around in JSFiddle", done: true },
      { text: "Build something awesome", done: true }
    ]
  }
}
</script>
<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  margin: 40px 0 0;
}

ul {
  list-style-type: none;
  padding: 0;
}

li {
  display: inline-block;
  margin: 0 10px;
}

a {
  color: #42b983;
}
</style>