/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let a=init;
    var increment=function(){
        a++;
        return a;
    }
    var decrement=function(){
        a--;
        return a;
    }
    var reset=function(){
        a=init;
        return a;
    }
    return { increment, decrement, reset };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */