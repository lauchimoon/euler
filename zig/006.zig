const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn sum_square(n: u64) u64 {
    const sum = (n * n * n / 3) + (n * n / 2) + (n / 6);
    return sum;
}

fn square_sum(n: u64) u64 {
    const sum = n * (n + 1) / 2;
    return sum * sum;
}

fn solve(n: u64) u64 {
    return square_sum(n) - sum_square(n) - 1;
}

pub fn main() !void {
    try stdout.print("{}\n", .{solve(100)});
}
