const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn solve(comptime pow: usize) u64 {
    const n: u1024 = comptime std.math.pow(u1024, 2, pow); // What a great language

    var answer: u64 = 0;
    const num = comptime std.fmt.comptimePrint("{}", .{n});

    for (num) |c| {
        answer += (c - '0');
    }

    return answer;
}

pub fn main() !void {
    try stdout.print("{}\n", .{solve(1000)});
}
