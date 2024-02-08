const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn is_prime(n: u64) bool {
    var nf: f64 = @floatFromInt(n);
    var limit: u64 = @intFromFloat(nf);
    for (2..limit) |i| {
        if (@mod(n, i) == 0) {
            return false;
        }
    }

    return true;
}

pub fn main() !void {
    const n = 2000000;
    var sum: u64 = 0;

    for (2..n) |i| {
        if (is_prime(i)) {
            sum += i;
        }
    }

    try stdout.print("{}\n", .{sum});
}
