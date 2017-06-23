#include "php_sasaya.h"

#if COMPILE_DL_SASAYA
    ZEND_GET_MODULE(sasaya)
#endif

static const zend_function_entry sasaya_functions[] = {
    PHP_FE(sasaya_hello, NULL)
    PHP_FE_END
};

zend_module_entry sasaya_module_entry = {
    STANDARD_MODULE_HEADER,
    "Sasaya",                       // your extension name
    sasaya_functions,               // where you define your functions
    NULL, // PHP_MINIT(sasaya),     // for module initialization
    NULL, // PHP_MSHUTDOWN(sasaya), // for module shutdown process
    NULL, // PHP_RINIT(sasaya)      // for request initialization
    NULL, // PHP_RSHUTDOWN(sasaya)  // for reqeust shutdown process
    PHP_MINFO(sasaya),              // for providing module information
    "0.1",
    STANDARD_MODULE_PROPERTIES
};

// Remove the comment if you want to initiazlie something (class entry, resource entry, constants ... etc)
/*
PHP_MINIT_FUNCTION(sasaya) {
    return SUCCESS;
}
PHP_MSHUTDOWN_FUNCTION(sasaya) {
    return SUCCESS;
}
*/

PHP_MINFO_FUNCTION(sasaya) {
    //
}

// Your functions here...
PHP_FUNCTION(sasaya_hello) {
    php_printf("Hello Sasaya");
    RETURN_TRUE;
}
