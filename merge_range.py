# Question from firecode.io
# Given a sorted list of integer ranges, merge all overlapping ranges.
# Example:
# Input  : [[1,10], [5,8], [8,15]]
# Output : [[1,15]]
# Input : [[5, 50], [25, 100], [150, 200]]
# Output : [[5, 100], [150, 200]]

# class Range:
#     def __init__(self):
#         self.lower_bound = -1
#         self.upper_bound = -1
#     def __init__(self,lower_bound,upper_bound):
#         self.lower_bound = lower_bound
#         self.upper_bound = upper_bound
#     def __str__(self):
#         return "["+str(self.lower_bound)+","+str(self.upper_bound)+"]"

def merge_ranges(input_range_list):
    if len(input_range_list) <= 1:
        return input_range_list
    result = []
    merged = input_range_list[0]
    for current in input_range_list:
        if(current.lower_bound <= merged.upper_bound):
            merged = Range(merged.lower_bound, max(merged.upper_bound, current.upper_bound))
        else:
            result.append(merged)
            merged = current
    result.append(merged)
    return result