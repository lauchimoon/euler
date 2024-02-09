const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn factorial(n: u256) u256 {
    if (n == 0) {
        return 1;
    } else {
        return n*factorial(n - 1);
    }
}

// n!/k!(n - k)!
fn c(n: u256, k: u256) u256 {
    return factorial(n)/(factorial(k)*(factorial(n - k)));
}

pub fn main() !void {
    try stdout.print("{}\n", .{c(40, 20)});
}
