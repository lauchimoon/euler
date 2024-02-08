const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn gcd(a: u64, b: u64) u64 {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, @mod(a, b));
    }
}

fn lcm(a: u64, b: u64) u64 {
    return a * b / gcd(a, b);
}

fn solve(until: u64) u64 {
    var num: u64 = 2;
    var nums = [_]u64{0} ** 17;
    for (3..until) |i| {
        num = lcm(num, i);
        nums[i - 3] = num;
    }

    return nums[nums.len - 1];
}

pub fn main() !void {
    var num = solve(20);
    try stdout.print("{}\n", .{num});
}
