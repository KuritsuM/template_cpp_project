//
// Created by kuritsumplus on 25.06.2025.
//

#ifndef TEMPLATE_CPP_PROJECT_IP_FILTER_H
#define TEMPLATE_CPP_PROJECT_IP_FILTER_H

#include <algorithm>
#include <cstdint>
#include <format>
#include <string>
#include <vector>

std::vector<std::string> sort_ip_addresses(const std::vector<std::string>& addresses) {
    std::vector<std::uint32_t> ip_addresses{};
    std::for_each(addresses.cbegin(), addresses.cend(), [&ip_addresses](const std::string_view current_address) -> void {
        std::uint32_t ip{};

        std::uint32_t buffer{};
        std::for_each(current_address.cbegin(), current_address.cend(), [&ip, &buffer](char currentSymbol) -> void {
            if (currentSymbol != '.') {
                buffer *= 10;
                buffer += (currentSymbol - '0');
            } else {
                ip |= buffer;
                ip <<= 8;
                buffer = 0;
            }
        });
        ip |= buffer;

        ip_addresses.push_back(ip);
    });

    std::sort(ip_addresses.begin(), ip_addresses.end(), std::greater<uint32_t>{});
    std::vector<std::string> sort_result{};
    std::for_each(ip_addresses.begin(), ip_addresses.end(), [&sort_result](std::uint32_t ip_bytes) {
        sort_result.push_back(
            std::format(
                "{}.{}.{}.{}",
                std::to_string(ip_bytes >> 24 & 0xFF),
                std::to_string(ip_bytes >> 16 & 0xFF),
                std::to_string(ip_bytes >> 8 & 0xFF),
                std::to_string(ip_bytes & 0xFF)
            )
        );
    });

    return sort_result;
}

#endif //TEMPLATE_CPP_PROJECT_IP_FILTER_H
