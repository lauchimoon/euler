const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn isPrime(n: u64) bool {
    var nf: f64 = @floatFromInt(n);
    var limit: u64 = @intFromFloat(nf);
    for (2..limit) |i| {
        if (@mod(n, i) == 0) {
            return false;
        }
    }

    return true;
}

fn solve(n: u64) u64 {
    var sum: u64 = 0;

    for (2..n) |i| {
        if (isPrime(i)) {
            sum += i;
        }
    }

    return sum;
}

pub fn main() !void {
    const n = 2000000;
    try stdout.print("{}\n", .{solve(n)});
}
