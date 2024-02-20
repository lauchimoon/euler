const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn d(n: u64) u64 {
    var nf: f64 = @floatFromInt(n);
    var limit: u64 = @intFromFloat(@sqrt(nf));
    var sum: u64 = 0;

    for (1..limit) |i| {
        if (@mod(n, i) == 0) {
            sum += i + n/i;
        }
    }

    if (sum > n) {
        return sum - n;
    } else {
        return n - sum;
    }
}

fn areAmicable(a: u64, b: u64) bool {
    return (d(a) == b and d(b) == a);
}

fn solve(limit: u64) u64 {
    var answer: u64 = 0;

    for (1..limit) |a| {
        for (1..limit) |b| {
            if (a != b and areAmicable(a, b)) {
                answer += a + b;
            }
        }
    }

    answer /= 2; // Remove repeated pairs

    return answer;
}

pub fn main() !void {
    try stdout.print("{}\n", .{solve(10000)});
}
