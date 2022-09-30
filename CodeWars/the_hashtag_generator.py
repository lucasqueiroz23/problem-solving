def generate_hashtag(s):
    
    hashtag = '#'
    s = s.split()
    
    for word in s:
        hashtag += word.capitalize()
    
    if not s or len(hashtag) > 140:
        return False
    
    return hashtag
