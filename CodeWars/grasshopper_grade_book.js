function getGrade (s1, s2, s3) {
  const grades = {
    '10': 'A',
    '9': 'A',
    '8': 'B',
    '7': 'C',
    '6': 'D',
    '0': 'F',
  }
  
  const average = Math.floor((s1+s2+s3)/30).toString();
  return average in grades ? grades[average] : 'F';
}
