#ifndef LLAMAMODEL_H_I_KNOW_WHAT_I_AM_DOING_WHEN_INCLUDING_THIS_FILE
#error This file is NOT meant to be included outside of llamamodel.cpp. Doing so is DANGEROUS. Be sure to know what you are doing before proceeding to #define LLAMAMODEL_H_I_KNOW_WHAT_I_AM_DOING_WHEN_INCLUDING_THIS_FILE
#endif
#ifndef LLAMAMODEL_H
#define LLAMAMODEL_H

#include <string>
#include <functional>
#include <vector>
#include "llmodel.h"

struct LLamaPrivate;
class LLamaModel : public LLModel {
public:
    LLamaModel();
    ~LLamaModel();

    bool loadModel(const std::string &modelPath) override;
    bool isModelLoaded() const override;
    size_t stateSize() const override;
    size_t saveState(uint8_t *dest) const override;
    size_t restoreState(const uint8_t *src) override;
    std::vector<Token> tokenize(const std::string&) override;
    std::string_view tokenToString(Token) override;
    Token sampleToken(PromptContext& ctx) override;
    bool evalTokens(PromptContext& ctx, const std::vector<int32_t> &tokens) override;
    int32_t getContextLength() override;
    const std::vector<Token>& getEndTokens() override;
    void setThreadCount(int32_t n_threads) override;
    int32_t threadCount() const override;

private:
    LLamaPrivate *d_ptr;
};

#endif // LLAMAMODEL_H
