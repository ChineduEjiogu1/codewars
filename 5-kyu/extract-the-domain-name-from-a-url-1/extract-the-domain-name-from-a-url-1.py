from urllib.parse import urlparse
​
def domain_name(url):
    
    parsed_url = urlparse(url)
    netloc = parsed_url.netloc
    
    if not netloc:
        netloc = parsed_url.path
​
    # Remove 'www.' prefix if present
    if netloc.startswith("www."):
        netloc = netloc[4:]
​
    # Remove the top-level domain (e.g., .com, .org, .net)
    # This approach assumes a single dot for the TLD,
    # which might not work for all cases like .co.uk
    if "." in netloc:
        parts = netloc.split(".")
        if len(parts) > 1:
            return parts[0] # Join all parts except the last one (TLD)
    return netloc