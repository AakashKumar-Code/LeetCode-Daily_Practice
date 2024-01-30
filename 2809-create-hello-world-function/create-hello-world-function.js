/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        const s="Hello World";
        return s;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */