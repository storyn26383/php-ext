--TEST--
Test SasayaClass->hello
--FILE--
<?php
$sasayaClass = new SasayaClass;
echo $sasayaClass->hello() . PHP_EOL;
echo $sasayaClass->setName('Sasaya')->hello() . PHP_EOL;
--EXPECT--
Hello World
Hello Sasaya
