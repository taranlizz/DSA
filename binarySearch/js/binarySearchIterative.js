/**
 * A searching algorithm. Iterative version.
 * Searches for a target number in a sorted array and returns an index of the target.
 * Complexity: O(log n)
 * @param {number[]} array - a sorted array to perform the search on
 * @param {number} target - a target number to search for in the array
 * @returns {number | null} - an index of the target value
 */

const binarySearch = (array, target) => {
  let low = 0;
  let high = array.length - 1;

  while (low <= high) {
    const midIdx = Math.floor((low + high) / 2);
    const currentItem = array[midIdx];

    if (currentItem === target) {
      return midIdx;
    }
    if (currentItem < target) {
      low = midIdx + 1;
    }
    if (currentItem > target) {
      high = midIdx - 1;
    }
  }
  return null;
};
