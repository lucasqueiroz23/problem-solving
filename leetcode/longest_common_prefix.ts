function longestCommonPrefix(strs: string[]): string {
    let lcp = '';
    strs.sort((a,b) => a.length - b.length);
    for(let i = 0; i < strs[0].length; i++){
        const char = strs[0][i];
        for(let j = 1; j < strs.length; j++) {
            if(strs[j][i] != char) {
                return lcp;
            }
        }
        lcp += char;
    }
    return lcp;
};

