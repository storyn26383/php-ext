#ifndef _PHP_SASAYA_H
    #define _PHP_SASAYA_H

    #ifdef HAVE_CONFIG_H
        #include "config.h"
    #endif

    #ifdef ZTS
        #include <TSRM.h>
    #endif

    #include <php.h>

    extern zend_module_entry sasaya_module_entry;
    extern zend_class_entry *sasaya_class_entry;

    PHP_MINIT_FUNCTION(sasaya);
    PHP_MSHUTDOWN_FUNCTION(sasaya);
    PHP_MINFO_FUNCTION(sasaya);

    PHP_FUNCTION(sasaya_hello);
    PHP_METHOD(SasayaClass, hello);
    PHP_METHOD(SasayaClass, setName);
#endif
