# cairo_graphics_tutorial

このプロジェクトは、 [Cairo graphics tutorial](http://zetcode.com/gfx/cairo/)でcairo
を学んだ時のサンプル集です。

## Compile

```bash
gcc example.c -o example `pkg-config --cflags --libs gtk+-3.0` 
```

### Pathの注意点

cairo_stroke(), cairo_fill()などを実行したらPathは空になるので再定義が必要です。

### Source

基本としてcolor, gradients, patterns, imagesがあります。

### Surface

描画先。CAIRO_SURFACE_TYPE_IMAGE, PDF, XLIB, WIN32,SVGなどいろいろあります。


