function to findLargestInteger(list):
    // Assume the first integer is the largest
    largest = list[0]

    // Iterate through the list
    for i from 1 to length(list) - 1:
        // Comparing integer with the assumed largest int
        if list[i] > largest:
            // Update largest if the current integer is larger
            largest = list[i];

    return largest;
