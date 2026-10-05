//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include <memory>
#include "game_state.hpp"
#include <optional>

class ValidationReport {
public:
    explicit ValidationReport(std::optional<std::string> report)
        : report_(std::move(report)) {}

    [[nodiscard]] bool ok() const { return !report_; }
    [[nodiscard]] std::optional<std::string> report() { return report_; }

private:
    std::optional<std::string> report_;
};

struct Action
{
    explicit Action(const std::shared_ptr<GameState>& state);
    [[nodiscard]] virtual ValidationReport validate() const = 0;
    virtual void execute() = 0;

    virtual ~Action() = default;

protected:
    std::shared_ptr<GameState> state;
};