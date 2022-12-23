class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if not n == 0:
            m -= 1
            n -= 1

            if m == -1:
                nums1.clear()
                nums1.extend(nums2)

            placer = len(nums1) - 1
            while placer >= 0:
                if n >= 0 and m >= 0:
                    if nums1[m] >= nums2[n]:
                        nums1[placer] = nums1[m]
                        m -= 1
                    elif nums2[n] > nums1[m]:
                        nums1[placer] = nums2[n]
                        n -= 1
                
                elif n < 0 and m >= 0:
                    nums1[placer] = nums1[m]
                    m -= 1

                elif m < 0 and n >= 0:
                    nums1[placer] = nums2[n]
                    n -= 1
                placer -= 1