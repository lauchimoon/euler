const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn solve() u64 {
    const Sunday = 0;
    const Monday = 1;
    const Tuesday = 2;
    const Wednesday = 3;
    const Thursday = 4;
    const Friday = 5;
    const Saturday = 6;

    const until_month = 12;
    const until_year = 2001;
    var days_count: u64 = 1;
    var answer: u64 = 0;

    const months = [_]u8{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const days = [_]u8{
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
    };

    for (1901..until_year) |year| {
        for (1..until_month + 1) |month| {
            var day: u64 = months[month - 1];
            if (year % 4 == 0 or year % 400 == 0 and (month - 1) == 1) {
                day += 1;
            }

            days_count += day;
            var n: u64 = @mod(days_count, 7);
            if (n > 0) {
                n -= 1;
            }

            n = days[n];
            if (n == Sunday) {
                answer += 1;
            }
        }
    }

    return answer/2;
}

pub fn main() !void {
    try stdout.print("{}\n", .{solve()});
}
