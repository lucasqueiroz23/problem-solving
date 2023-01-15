function findNeedle(haystack) {
  const needlePosition = haystack.findIndex(item => item === 'needle');
  return `found the needle at position ${needlePosition}`;
}
