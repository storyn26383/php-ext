#include "php_sasaya.h"

#if COMPILE_DL_SASAYA
    ZEND_GET_MODULE(sasaya)
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_set_name, 0, 0, 1)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

const zend_function_entry sasaya_functions[] = {
    PHP_FE(sasaya_hello, NULL)
    PHP_FE_END
};

const zend_function_entry sasaya_class_functions[] = {
    PHP_ME(SasayaClass, hello, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(SasayaClass, setName, arginfo_set_name, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

zend_module_entry sasaya_module_entry = {
    STANDARD_MODULE_HEADER,
    "Sasaya",                       // your extension name
    sasaya_functions,               // where you define your functions
    PHP_MINIT(sasaya),              // for module initialization
    PHP_MSHUTDOWN(sasaya),          // for module shutdown process
    NULL, // PHP_RINIT(sasaya)      // for request initialization
    NULL, // PHP_RSHUTDOWN(sasaya)  // for reqeust shutdown process
    PHP_MINFO(sasaya),              // for providing module information
    "0.1",                          // your extension version
    STANDARD_MODULE_PROPERTIES
};

zend_class_entry *sasaya_class_entry;

PHP_MINIT_FUNCTION(sasaya) {
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "SasayaClass", sasaya_class_functions);

    sasaya_class_entry = zend_register_internal_class(&ce);

    zend_declare_property_string(sasaya_class_entry, "name", sizeof("name") - 1, "World", ZEND_ACC_PROTECTED);

    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(sasaya) {
    return SUCCESS;
}

PHP_MINFO_FUNCTION(sasaya) {
    //
}

// Your functions here...
PHP_FUNCTION(sasaya_hello) {
    RETURN_STRING("Hello Sasaya");
}

PHP_METHOD(SasayaClass, hello) {
    zval *this, rv;
    zend_string *name, *message;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    this = getThis();

    name = zval_get_string(
        zend_read_property(sasaya_class_entry, this, "name", sizeof("name") - 1, 1, &rv)
    );

    message = strpprintf(0, "Hello %s", ZSTR_VAL(name));

    RETURN_STR(message);
}

PHP_METHOD(SasayaClass, setName) {
    zval *this, *name;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "z", &name) == FAILURE) {
        RETURN_NULL();
    }

    zend_update_property(sasaya_class_entry, getThis(), "name", sizeof("name") - 1, name);
}
