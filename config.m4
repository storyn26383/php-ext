PHP_ARG_ENABLE(sasaya, whether to enable sasaya extension support, 
  [--enable-sasaya Enable sasaya extension support])

if test $PHP_SASAYA != "no"; then
    PHP_NEW_EXTENSION(sasaya, php_sasaya.c, $ext_shared)
fi
