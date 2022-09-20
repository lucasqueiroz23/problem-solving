export default function isSquare(n: number): boolean {
  if(n < 0 || !Number.isInteger(Math.sqrt(n)))
    return false;
  return true;
};
