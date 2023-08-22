let memo = 0;
function createCounter(n: number): () => number {
    memo = n;
    return function() {
        memo++;
        return memo - 1;
    }
}


/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
