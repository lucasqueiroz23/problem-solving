/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    const digits = getNumberArray(x);

    for(let i = 0, j = digits.length - 1; i<=j;i++, j--){
        if(digits[i] != digits[j])
            return false;
    }
    return digits.length > 0 || x == 0 ? true : false;
};

function getNumberArray(x){
    const arr = [];
    while(x>0){
        arr.push(x%10);
        x = Math.floor(x/10);
    }

    return arr;
}
