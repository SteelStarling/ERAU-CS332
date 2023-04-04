# Assign this lambda function to the name on the left
hello <- function(name) {
    # R has print, but it marks output with [1], cat does not
    cat("Hello", name, "\n")
}

main <- function() {
    cat("Hello World!\n")
    # collect the commandline arguments into an array
    # the trailingOnly setting omits default switches from the list
    args <- commandArgs(trailingOnly = TRUE)
    for (i in 1:length(args)) {
        hello(args[i])
    }
}

main();

