const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn isPrime(n: u64) bool {
    for (2..n) |i| {
        if (@mod(n, i) == 0) {
            return false;
        }
    }

    return true;
}

fn solve(comptime idx: u64) u64 {
    var primes = [_]u64{0} ** idx;
    var p_idx: u64 = 0;
    var n: u64 = 2;
    while (p_idx < idx) {
        if (isPrime(n)) {
            primes[p_idx] = n;
            p_idx += 1;
        }

        n += 1;
    }

    return primes[primes.len - 1];
}

pub fn main() !void {
    try stdout.print("{}\n", .{solve(10001)});
}
