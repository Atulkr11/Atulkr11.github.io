<?php
function minify($content, $path = '') {
  $output = preg_replace(
        array(
          '/ {2,}/',
          '/<!--.?-->|\t|(?:\r?\n[ \t])+/s'
        ), 
        array(
          ' ',
          ''
        ), 
        $content
      );
  return $output;
}

//minify JavaScript
//$url = "https://cdnjs.cloudflare.com/ajax/libs/jquery/3.6.0/jquery.js";
//echo minify(file_get_contents($url));
//minify HTML
$url = "https://reeteshghimire.com.np/";
echo minify(file_get_contents($url));
//minify CSS
//$url = "https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/5.2.0-beta1/css/bootstrap.css";
//echo minify(file_get_contents($url));

?>