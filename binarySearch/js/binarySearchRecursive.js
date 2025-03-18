/**
 * A searching algorithm. Recursive version.
 * Searches for a target number in a sorted array and returns an index of the target.
 * Complexity: O(log n)
 * @param {number[]} array - a sorted array to perform the search on
 * @param {number} target - a target number to search for in the array
 * @param {number} [low = 0] - a start index of a part of the array to perform search in, must be less than high param (default: 0).
 * @param {number} [high = array.length - 1] - an end index of the part of the array to perform search in,
 *                                             must be greater than low param (default: array.length - 1).
 * @returns {number | null} - an index of the target value
 */

const binarySearch = (array, target, low = 0, high = array.length - 1) => {
  if (low > high) return null;

  const midIdx = Math.floor((low + high) / 2);
  const currentItem = array[midIdx];

  if (currentItem === target) {
    return midIdx;
  }
  if (currentItem > target) {
    return binarySearch(array, target, low, midIdx - 1);
  }
  if (currentItem < target) {
    return binarySearch(array, target, midIdx + 1, high);
  }
};
