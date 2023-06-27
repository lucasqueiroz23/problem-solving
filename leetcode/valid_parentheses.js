/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    // string length must be even
    if (s.length % 2 === 1) return false;

    s = s.split('');   
    const q = [];
    for(const char of s) {
        switch(char) {
            case '(':
                q.unshift(')');
                break;
            case '[':
                q.unshift(']');
                break;
            case '{':
                q.unshift('}');
                break;
            case '}':
            case ']':
            case ')':
                if(char !== q.shift()) 
                    return false;
                break;
            default:
                break;
        }
    }

    return q.length === 0 ;
};
