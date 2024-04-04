const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn factorial(n: u1024) u1024 {
    if (n == 0) {
        return 1;
    } else {
        return n*factorial(n - 1);
    }
}

fn solve() u64 {
    const n: u1024 = comptime factorial(100);
    var answer: u64 = 0;
    const num = comptime std.fmt.comptimePrint("{}", .{n});

    for (num) |c| {
        answer += (c - '0');
    }

    return answer;
}

pub fn main() !void {
    try stdout.print("{}\n", .{solve()});
}
